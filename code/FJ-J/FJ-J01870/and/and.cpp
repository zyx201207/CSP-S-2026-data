#include<bits/stdc++.h>
using namespace std;
int a[200005][35],b[200005],tot=0,tot2=0;long long ans=0;
void cccfff(int x,int n){
	int i=0;
	while(x!=0){
		a[n][i]=(x%2);
		x/=2;
		a[0][i]+=a[n][i];
		i++;
		
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cccfff(x,i);
	}
	int jl=-1;
	for(int i=34;i>=0;i--){
		if(a[0][i]>=m){
			for(int j=1;j<=n;j++){
				if(a[j][i]==1){
					b[++tot]=j;
				}
			}
			jl=i;
			ans+=pow(2,i);
			break;
		}
	}
	if(jl==-1){
		cout<<0;
		return 0;
	}
	for(int i=jl-1;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=tot;j++){
			if(a[b[j]][i]==1){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=tot;j++){
				if(a[b[j]][i]==1){
					b[++tot2]=b[j];
				}
			}
			tot=tot2;
			ans+=pow(2,i);
		}
	}
	cout<<(long long)ans;
	return 0;
}
