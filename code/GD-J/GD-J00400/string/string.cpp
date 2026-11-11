#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,l;
	char s;
}a[200005],b[200005]; 
long long n,cnt,ans=1,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		if(a[cnt].s==c) a[cnt].l+=x;
		else{
			a[++cnt].x=ans;
			a[cnt].l=x;
			a[cnt].s=c;
		}
		ans+=x;
	}
	ans=1;
	for(int i=1;i<=cnt;i++){
		b[i].x=ans;
		b[i].l=a[cnt-i+1].l;
		b[i].s=a[cnt-i+1].s;
		ans+=a[cnt-i+1].l;
	}
	long long i=1,j=1;
	while(i<=cnt && j<=cnt){
		if(a[i].s==b[j].s) {
			if(a[i].l>b[j].l){
				sum+=a[i].l-b[j].l;
				a[i].l-=b[j].l;
				j++;
			}else if(a[i].l<b[j].l) {
				sum+=b[j].l-a[i].l;
				b[j].l-=a[i].l;
				i++;
			}
			else{
				i++;
				j++;
			}
		}
		else {
			if(a[i].l>b[j].l){
				sum+=b[j].l;
				a[i].l-=b[j].l;
				j++;
			}else if(a[i].l<b[j].l) {
				sum+=a[i].l;
				b[j].l-=a[i].l;
				i++;
			}
			else{
				sum+=a[i].l;
				i++;
				j++;
			}
		}
	}
	cout<<sum/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
