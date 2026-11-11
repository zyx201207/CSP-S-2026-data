/*#include<bits/stdc++.h>
using namespace std;
long long n,asw;
struct T {
	int ip;
	char id;
}a[10086];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i].ip>>a[i].id;	
	}
	int l=1,r=n;
	while(l<r){
		int m=min(a[l].ip,a[r].ip);
		if(a[l].id!=a[r].id){
			asw+=m;
		}
		a[l].ip-=m;
		a[r].ip-=m;
		if(a[l].ip==0) l++;
		if(a[r].ip==0) r--;
	}
	cout<<asw;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,asw,a[10086],s[10086];
void dfs(int step,int z,int y){
	if(step==z+1){
		if(y==m){
			int fk=0;
			for(int i=1;i<=n;i++) if(s[i]) fk++;
			if(fk==m){
			long long f=0,ls=0;
			for(int i=1;i<=n;i++){
				if(s[i]&&f==0){
					ls=a[i];
					f=1;
				}
				else if(s[i]) ls&=a[i];
				//cout<<s[i]<<" ";
			}
			//if(asw<ls) cout<<"wdf ";
			//cout<<'\n';
		asw=max(asw,ls);
				
			}
		}
		return;
	}
	if(y<m){
		s[step]=1;
		dfs(step+1,z,y+1);
	}
	s[step]=0;
	dfs(step+1,z,y);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,n,0);
	cout<<asw;
    return 0;
}

