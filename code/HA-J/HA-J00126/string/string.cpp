#include<bits/stdc++.h>
using namespace std;
long long n;
struct Node{
	long long a;
	char c;
}a[1000001],b[1000001];
long long s=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		b[n-i+1].a=a[i].a;
		b[n-i+1].c=a[i].c;
	}
	long long i=1,j=1;
	while(i<=n&&j<=n){
		if(a[i].a==b[j].a){
			if(a[i].c!=b[j].c){
				s+=a[i].a;
			}
			i++,j++;
		}else if(a[i].a>b[j].a){
			a[i].a-=b[j].a;
			if(a[i].c!=b[j].c){
				s+=b[j].a;
			}
			b[j].a=0;
			j++;
		}else if(a[i].a<b[j].a){
			b[j].a-=a[i].a;
			if(a[i].c!=b[j].c){
				s+=a[i].a;
			}
			a[i].a=0;
			i++;
		}
	}
	cout<<s/2;
	return 0;
}

