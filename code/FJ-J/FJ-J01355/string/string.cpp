#include<bits/stdc++.h>
using namespace std;
string a;
long long b,c[200005],r,q;
char d[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>c[i]>>d[i];
	}r=b;
	for(int i=1;i<r;){
		if(c[i]<c[r]&&d[i]==d[r]){
			c[r]-=c[i];
			i++;
		}else if(c[i]>c[r]&&d[i]==d[r]){
			c[i]-=c[r];
			r--;
		}else if(c[i]==c[r]&&d[i]==d[r]){
			i++;
			r--;
		}else if(d[i]!=d[r]){
			if(c[i]>c[r]){
				q+=c[r];
				c[i]-=c[r];
				//cout<<c[i]<<' '<<c[r]<<' '<<d[i]<<' '<<d[r]<<endl;
				r--;
			}else if(c[i]<c[r]){
				q+=c[i];
				c[r]-=c[i];
				//cout<<c[i]<<' '<<c[r]<<' '<<d[i]<<' '<<d[r]<<endl;
				i++;
			}else if(c[i]==c[r]){
				q+=c[r];
				//cout<<d[i]<<' '<<d[r]<<' '<<(c[i]==c[r]&&d[i]==d[r])<<endl;
				r--;
				i++;
			}
		}
	}cout<<q;
	return 0;
}
