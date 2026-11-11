//GZ-J00291，石鑫，凯里市第十三中学 
#include<bits/stdc++.h>
using namespace std;
bool a[200005][32];
int s[32];
bool v[200005];
long long sv=0;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	long long x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=0;x>0;j++){
			a[i][j]=x&1;
			s[j]+=x&1;
			x=x>>1;
		}
	}
	
/*	
	for(int i=1;i<=n;i++){
		for(int j=0;j<32;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	*/ 
	
	//cout<<s[0]<<s[1]<<s[2]<<s[3]<<'\n';
	long long ans=0; 
	for(int i=31;i>=0;i--){
		/*
		cout<<'\n'<<'\n';
		cout<<ans<<' '<<i<<' '<<sv<<'\n';
		for(int i=1;i<=n;i++){
			for(int j=0;j<=3;j++){
				cout<<a[i][j]<<' ';
			}
			cout<<'\n';
		}
		for(int j=1;j<=n;j++){
			if(v[j]==1)cout<<j;
		}*/
		
		if(s[i]<m){//2^i为1的个数小于m 此位不可能保留 
			continue;
		}
		else{
			if(sv==0){//2^i首次大于m 初始化 
			ans+=pow(2,i);
				for(int j=1;j<=n;j++){
					if(a[j][i]==1){
						v[j]=1;
						sv++;
					}
				}
			}
			else{//2^i再次大于m 
				int sa=0;
				if(sv==m){
					for(int j=1;j<=n;j++){
						if(v[j]==1 && a[j][i]==1){
							ans+=pow(2,i);
							break;
						}
					}
					continue;
				}
				for(int j=1;j<=n;j++){
					if(a[j][i]==0 && v[j]==1){
						sa++;
					}
				}
				if(sv-sa>=m){//筛掉数字后 仍存在不小于m个数字 
					ans+=pow(2,i);
					//cout<<sa;
					for(int j=1;j<=n;j++){
						if(a[j][i]==0 && v[j]==1){
							v[j]=0;
							sv--;
						}
					}
				}
				else{
					continue;
				}
			}
		}
	}
	
	cout<<ans;
	return 0;
}
