#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500007],d=0,e,o[500007],cnt[300007];
bool t[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int x=1;x<=a;x++){
		cin>>c[x];
	} 
	for(int x=1;x<=a;x++){
		for(int y=1;y<=b;y++){
			t[y]=0;
		}
		e=0;
		for(int y=x;y<=a;y++){
			if(t[c[y]]==0){
				t[c[y]]=1;
				e++;
				o[e]=c[y];
			}else{
				d=0;
				for(int z=e;z>=1;z--){
					if(o[z]!=c[y]){
						t[o[z]]=0;
						o[z]=0;
						d++;
					}else{
						break;
					}
				}
				e-=d;
				t[c[y]]=1;
			}
		}
		for(int x=1;x<=e;x++){
			cnt[o[x]]++;
			o[x]=0;
		}
	}
	for(int x=1;x<=b;x++){
		cout<<cnt[x]<<" ";
	}
	return 0;
} 
