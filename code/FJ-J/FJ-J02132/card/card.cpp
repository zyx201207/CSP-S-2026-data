#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int b[N];
int p[N];  
int fa[N];
int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		fa[a[i]]++;
	}
	for(int i=1;i<n;i++){
		queue<int> s;
		int ne[N];
		for(int z=i;z<=n;z++){
			ne[b[z]]++;
			if(ne[b[z]]>1){
				int len=s.size(),f=0;
				for(int j=1;j<=len;j++){
					int o=s.front();
					s.pop();
					f++;
					if(o==b[z]){
						f--;
						break;
					}
				s.push(o);
			}
			for(int j=1;j<=f;j++){
				int ooo=s.front();
				s.pop();
				s.push(ooo);
			}
			for(int j=1;j<=s.size()-f;j++){
				s.pop();
			}
			s.push(b[z]);
		}
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		
		}
		for(int i=1;i<=s.size();i++){
			int oo=s.front();s.pop();
			p[oo]++;
		}
	}
	p[a[n]]++;
	for(int i=1;i<=m;i++)
		cout<<p[i]<<" ";
	return 0;
}
