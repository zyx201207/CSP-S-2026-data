#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],u[500010]; 
struct d{
	long long a;
	int b;
}e;
vector<d>p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			e.a=a[j];
			e.b=0;
			p.push_back(e);
		    for(int k=0;k<p.size()-1;k++){
		    	if(p[k].a==a[j]&&p[k].b!=1){
		    	   for(int g=k;g<p.size()-1;g++){
					   p[k].b=1;
				   }
				   break;
				}
			}
		}
		for(int j=0;j<p.size();j++){
		    if(p[j].b==0){
		       u[p[j].a]++;
			}
		}
		p.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<u[i]<<" ";
	}
	return 0;
} 
