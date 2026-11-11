#include<bits/stdc++.h>
using namespace std;
struct node{
	long long pa;
	char pc;
}l[200005],r[200005];
long long n,a[200005],ans,res,m=1,j;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n%2==1){
		for(int i=1;i<=n;i++){
			l[i].pa=a[i];
			l[i].pc=c[i];
			r[i].pa=a[i];
			r[i].pc=c[i];
		}
		j=n;
		while(m<j){
			if(l[m].pc!=r[j].pc){
				if(l[m].pa>r[j].pa){
					l[m].pa-=r[j].pa;
					ans+=r[j].pa;
					j--;
				}else if(r[j].pa>l[m].pa){
					r[j].pa-=l[m].pa;
					ans+=l[m].pa;
					m++;
				}else{
					ans+=l[m].pa;
					j--;m++;
				}
			}
			else{
				if(l[m].pa>r[j].pa){
					l[m].pa-=r[j].pa;
					j--;
				}else if(r[j].pa>l[m].pa){
					r[j].pa-=l[m].pa;
					m++;
				}else{
					j--;m++;
				}
			}
		}
	}
	if(n%2==0){
		for(int i=1;i<=n;i++){
			l[i].pa=a[i];
			l[i].pc=c[i];
			r[i].pa=a[i];
			r[i].pc=c[i];
		}
		j=n;
		while(m<j){
			if(l[m].pc!=r[j].pc){
				if(l[m].pa>r[j].pa){
					l[m].pa-=r[j].pa;
					ans+=r[j].pa;
					j--;
				}else if(r[j].pa>l[m].pa){
					r[j].pa-=l[m].pa;
					ans+=l[m].pa;
					m++;
				}else{
					ans+=l[m].pa;
					j--;m++;
				}
			}
			else{
				if(l[m].pa>r[j].pa){
					l[m].pa-=r[j].pa;
					j--;
				}else if(r[j].pa>l[m].pa){
					r[j].pa-=l[m].pa;
					m++;
				}else{
					j--;m++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

