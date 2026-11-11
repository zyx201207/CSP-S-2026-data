#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
long long a[200005];
char b[200005];
struct st{
	long long ans;
	char x;
};
void os(){
	long long q=sum/2,ll=0,rl=0;
	st l[n],r[n];
	while(1){
		if(q<=a[ll]){
			l[ll].ans=q;
			l[ll].x=b[ll];
			break;
		}
		q-=a[ll];
		l[ll].ans=a[ll];
		l[ll].x=b[ll];
		ll++;
	}
	q=sum/2;
	while(1){
		if(q<=a[n-rl-1]){
			r[rl].ans=q;
			r[rl].x=b[n-rl-1];
			break;
		}
		q-=a[n-rl-1];
		r[rl].ans=a[n-rl-1];
		r[rl].x=b[n-rl-1];
		rl++;
	}
	long long s2=0;
    for(int i=0,j=0;i<=ll,j<=rl;){
    	if(l[i].x==r[j].x){
    		if(l[i].ans>r[j].ans){
    			l[i].ans=l[i].ans-r[j].ans;
    			j++;
			}
			else{
				if(l[i].ans<r[j].ans){
					r[j].ans -=l[i].ans ;
					i++;
				}
				else{
					i++,j++;
				}
			}
		}
		else{
			if(l[i].ans>r[j].ans){
    			l[i].ans=l[i].ans-r[j].ans;
    			s2+=r[j].ans; 
    			j++;
			}
			else{
				if(l[i].ans<r[j].ans){
					r[j].ans -=l[i].ans ;
					s2+=l[i].ans;
					i++;
				}
				else{
					s2+=l[i].ans;
					i++,j++;
				}
			}
		}
	}
	printf("%lld",s2);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(b[0]==b[1]){
			cout<<0;
		}
		else{
			printf("%lld",min(a[0],a[1])); 
		}
	}
    else{
    	os(); 
	}
	return 0;
}
