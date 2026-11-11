#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long n,ans=0; 
struct E{
	int num;
	int ac;
}a[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a1; char c;
		cin>>a1>>c;
		a[i].ac=c-'a'+1;
		a[i].num=a1;
	}
	int le=1,re=n;
	while(le<re){
		if(a[le].ac==a[re].ac) {
			if(a[le].num<a[re].num) {  a[re].num-=a[le].num; le+=1;}
			else if(a[le].num>a[re].num) {  a[le].num-=a[re].num; re-=1;}
			else { le+=1; re-=1; }
		}else{
			if(a[le].num<a[re].num) {
				ans += a[le].num;  a[re].num -= a[le].num; le += 1; }
			else if(a[le].num>a[re].num) {				
				ans += a[re].num;  a[le].num -= a[re].num; re -= 1;
			}
			else { ans+=a[le].num; le+=1; re-=1; }
		}
	}
	cout<<ans;
	return 0;
} 

