#include<bits/stdc++.h>
using namespace std;
int n;
long long l,d;
struct nooo{
	int s,ss;
	char c;
}a[200010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		a[i].ss=a[i-1].ss+a[i-1].s;
		l+=a[i].s;
	}
	for(int i=1,j=n;i<j;){
//		cout<<i<<":"<<a[i].s<<"|"<<a[i].c<<" "<<j<<":"<<a[j].s<<"|"<<a[j].c<<"\n";
		if(a[i].s<a[j].s){
			if(a[i].c!=a[j].c){
				d+=a[i].s;
			}
			a[j].s-=a[i].s;
			i++;
		}else if(a[i].s>a[j].s){
			if(a[i].c!=a[j].c){
				d+=a[j].s;
			}
			a[i].s-=a[j].s;
			j--;
		}else{
			if(a[i].c!=a[j].c){
				d+=a[i].s;
			}
			i++,j--;
		}
//		cout<<i<<":"<<a[i].s<<"|"<<a[i].c<<" "<<j<<":"<<a[j].s<<"|"<<a[j].c<<"\n";
	}
	cout<<d;
	return 0;
}
