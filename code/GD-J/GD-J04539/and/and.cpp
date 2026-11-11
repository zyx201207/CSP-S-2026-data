#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005];
vector<int>c[200005];
vector<int>vi[200005];
int cnt=0;
void si(int u){
	string o;
	int x;
	x=a[u];
	while(x>0){
		if(x%2==0){
			o+='0';
			x/=2;
		}else{
			o+='1';
			x/=2;
		}
	}
	for(int i=o.size()-1;i>=0;i--){
		c[u].push_back(o[i]-'0');
	}
}
void d(int u,int sh){
	if(u==n){
		int ans=0;
		int p=0;
		for(int i=vi[u-1].size()-1;i>=0;i--){
			if(vi[u-1][i]==1){
				ans+=pow(2,p);
			}
			p++;
		}
		if(ans>cnt){
			cnt=ans;
		}
	}
	for(int i=sh+1;i+n-m<n;i++){
		b[u]=i;
		if(c[i].size()==0){
			si(i);
		}
		if(u!=0){
			int k1=c[i].size();
			int k2=vi[u-1].size();
			if(k1>k2){
				int kk1=0;
				int kk2=0;
				for(int o=0;o<k1-k2;o++){
					vi[u].push_back(c[i][o]);
					kk1++;
				}
				for(int o=kk1;o<k1;o++){
					if(c[i][kk1]==1&&vi[u-1][kk2]==1){
						vi[u].push_back(1);
					}else{
						vi[u].push_back(0);
					}
					kk1++;
					kk2++;
				}
			}else{
				int kk1=0;
				int kk2=0;
				for(int o=0;o<k2-k1;o++){
					vi[u].push_back(vi[u-1][o]);
					kk2++;
				}
				for(int o=kk2;o<k2;o++){
					if(c[i][kk1]==1&&vi[u-1][kk2]==1){
						vi[u].push_back(1);
					}else{
						vi[u].push_back(0);
					}
					kk1++;
					kk2++;
				}
			}
		}else{
			string o;
			int x;
			x=a[i];
			while(x>0){
				if(x%2==0){
					o+='0';
					x/=2;
				}else{
					o+='1';
					x/=2;
				}
			}
			for(int i=o.size()-1;i>=0;i--){
				vi[u].push_back(o[i]-'0');
			}
		}
		d(u+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	d(0,-1);
	cout<<cnt;
}
