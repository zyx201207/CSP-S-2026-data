#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int wei[200005][35];
int s[35];
vector<int> g[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int num=a[i];
		for(int j=31;j>=0;j--){
			long long x=pow(2,j);
			if(x<=num){
				wei[i][j]=1;
				s[j]++;
				num-=x;
			}
			
		}
//		for(int j=0;j<=30;j++){
//			cout<<wei[i][j];
//		}
//		cout<<endl;
	}
//	sort(a+1,a+1+n,greater<int>());
	int k=-1;
	for(int i=30;i>=0;i--){
		if(s[i]>=m){
			k=i;
			break;
		}
	}
	if(k==-1){
		cout<<0;
		return 0;
	}
	int ans=pow(2,k);
	for(int i=1;i<=n;i++){
		if(wei[i][k]!=0){
			g[1].push_back(i);
		}
	}
//	for(int fuction:g){
//		cout<<fuction<<" ";
//	}
	for(int i=2;i<=30;i++){
		int mp[35];
		memset(mp,0,sizeof(mp));
		for(int s:g[i-1]){
			for(int j=k-1;j>=0;j--){
				mp[j]+=wei[s][j];
//				cout<<s<<" "<<j<<" "<<wei[s][j]<<endl; 
			}
		}
		int sub=k;
		for(int j=sub-1;j>=0;j--){
			if(mp[j]>=m){
//				cout<<mp[j]<<" ";
				k=j;
				break;
			}	
		}
		if(k==sub){
			cout<<ans;
			return 0;
		}
//		cout<<k<<endl;
		ans+=pow(2,k);
		for(int s:g[i-1]){
			if(wei[s][k]!=0){
				g[i].push_back(s);
//				cout<<s<<" ";
			}
		}
//		cout<<endl;
	}
	cout<<ans;
	return 0;
}

