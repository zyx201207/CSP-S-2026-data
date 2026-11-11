#include<bits/stdc++.h>
using namespace std;
struct hws{
	long long s;
	char zm;
}a[1000000];
long long n,b,t,w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].s>>a[i].zm;
	}
	t=1;
	w=n;
	while(t!=w){
		if(a[t].zm==a[w].zm){
			if(a[t].s>=a[w].s){
				a[t].s-=a[w].s;
				w--;
			}else{
				a[w].s-=a[t].s;
				t++;
			}
		}
		else{
			if(a[t].s>=a[w].s){
				b+=a[w].s;
				a[t].s-=a[w].s;
				w--;
			}else{
				b+=a[t].s;
				a[w].s-=a[t].s;
				t++;
			}
		}
	}
	cout<<b;
	return 0;
} 
