#include<bits/stdc++.h> 
using namespace std;
long long n,c,w,p1=1,p2,ans,h1,h2,s1,s2;
struct node{
	long long l;
	char q;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].l>>a[i].q;
	
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	p2=n;



		while(p1<p2){
			
			if(a[p1].l==0){
				p1++;
			}
			if(a[p2].l==0){
				p2--;
			}
			if(a[p1].q==a[p2].q){
				long long t=min(a[p2].l,a[p1].l);
				a[p1].l-=t;
				a[p2].l-=t;
			}else if(a[p1].l>a[p2].l){
			ans+=a[p2].l;
			a[p1].l-=a[p2].l;
				p2--;
				
				
			}else
			if(a[p1].l<a[p2].l){
				ans+=a[p1].l;
				a[p2].l-=a[p1].l;
				p1++;
				
			}else{
				ans+=a[p1].l;
				p1++;
				p2--;
			}
			
			
		}
		

	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
