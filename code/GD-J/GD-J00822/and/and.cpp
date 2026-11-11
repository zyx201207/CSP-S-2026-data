#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200009],b[35],d,vis[31],ah;
vector<long long> c[31]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	b[0]=1;
	for(int i=1;i<=30;i++)b[i]=b[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if((a[i]&b[j])==b[j]){
				c[j].push_back(a[i]);
				//cout<<a[i]<<":"<<(a[i]&b[j])<<" // ";
			}
		}
		//cout<<endl;
	}
	//cout<<"/ ";
	for(int i=30;i>=0;i--){
		if(c[i].size()>=m){
			ah=c[i].size();
			for(int j=30;j>i;j--){
				if(vis[j]==0)continue;
				for(int z=0;z<c[i].size();z++){
					if(c[i][z]!=0&&(c[i][z]&b[j])==0){
						//cout<<c[i][z]<<endl;
						c[i][z]=0;
						ah--;
					}
				}
			}
			vis[i]=1;
			if(ah>=m){
				d+=b[i];
				//cout<<b[i]<<endl;
			}
		}
		
		//cout<<"// ";
	}
	cout<<d;
	return 0;
}
