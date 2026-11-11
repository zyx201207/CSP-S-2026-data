#include<bits/stdc++.h>

using namespace std;
long long n,m,d[200100],s[100],mx,ans;
void cw(long long x){
	long long y=0;
	while(x){
		s[++y]+=x%2;
		mx=max(mx,y);
		x/=2;
	}return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	vector<int> v;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>d[i];
		cw(d[i]);
	}for(long long i=mx;i>=1;i--){
		if(s[i]>=m){
			int ta=0;
			for(int j=1;j<=n;j++){
				int t=d[j],ty=0;
				int ts[100];
				memset(ts,0,sizeof(ts));
				while(t){
					ts[++ty]=t%2;
					t/=2;
				}bool b=1;
				v.push_back(i);
				for(int q:v){
					if(ts[q]==0){
						b=0;
						break;
					}
				}ta+=b;
				v.pop_back();
			}if(ta>=m){
				v.push_back(i);
			}
		}
	}for(int q:v){
		ans+=pow(2,q-1);
	}cout<<ans;
	return 0;
}

