#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct aaa{
	long long a;
	char c;//a是长度，c是字符 
}a[N];
int n;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].c;
	for(int i=1;i<=n/2;i++){
		int j=n-i+1;
		if(a[i].a==a[j].a) continue;
		if(a[i].c!=a[j].c){
			if(a[i].a>a[j].a){
				sum+=a[i].a;
				a[i].a-=a[j].a;
			} 
			else if(a[i].a==a[j].a) sum+=a[i].a;
			else if(a[i].a<a[j].a){
				sum+=a[j].a;
				a[j].a-=a[i].a;
			}
		}
	}
	cout<<sum;
	return 0;
}
