#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int> r[20020];
int s[20020];
bool v[20020];
int ans[20020];
int ld[20020];
void de(int x,int n){
	v[x]=1;
	for(unsigned int i=0;i<r[x].size();i++){
		if(v[i]==0){
			if(s[i]==s[x]+r[x][i]){
				ans[i]++;
			}
			s[i]=min(s[x]+r[x][i],s[i]);
		}
	}
	int minn=2147483646,minnp=0;
	int flag=1;
	for(int i=1;i<=n;i++){
		if(minn>s[i]&&v[i]==0){
			minnp=i;
			minn=s[i];
			flag=0;
		}
	}
	if(flag==1){
		return;
	}
	de(minnp,n);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		memset(r,0,sizeof(r));
		memset(s,2147483646,sizeof(s));
		memset(v,0,sizeof(v));
		memset(ans,0,sizeof(ans));
		memset(ld,0,sizeof(ld));
		int n,d;
		cin >> n >> d;
		int l=1;
		for(int i=1;i<=n;i++){
			cin >> ld[i];
			
			if(l==i){
				continue;
			}
			for(int j=l;j<i;j++){
				int q=ld[i]-ld[j];
				if(q<=d){
					r[j].push_back(i);
					r[i].push_back(j);
					r[j][i]=q;
				}else{
					l++;
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(unsigned int i=0;i<r[j].size();i++){
					cout << j << " " << i  << " " <<r[i][j] << endl;
			}
		}
		s[1]=0;
		de(1,n);
		int k=0;
		for(int i=1;i<=n;i++){
			if(ans[i]==2){
				k++;
			}
		}
		cout << k << endl;
	}
	return 0;
}
