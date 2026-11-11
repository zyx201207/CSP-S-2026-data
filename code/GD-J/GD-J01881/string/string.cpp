#include<bits/stdc++.h>
using namespace std;
struct uct{
	long long t;
	char c;
}a[200005];
long long n,mid,len,cnt;
stack<uct> st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(long long i=1;i<=n;i++){
		scanf("%lld %s",&a[i].t,&a[i].c);
		len+=a[i].t;
	}
	mid=len/2;
	long long s=0,j=1;
	for(;j<=n&&s<mid;j++){
		if(mid-s>=a[j].t){
			s+=a[j].t;
			st.push({a[j].t,a[j].c});
			a[j].t=0;
		}else{
			st.push({mid-s,a[j].c});
			a[j].t-=(mid-s);
			s=mid;
			break;
		}
	}
	if(len%2)a[j].t--;
	uct pos=st.top();
	st.pop();
	while(j<=n){
		if(pos.c==a[j].c){
			if(pos.t>=a[j].t){
				a[j].t=0;
				j++;
			}else{
				a[j].t-=pos.t;
				pos=st.top();
				st.pop();
			}
		}
		else{
			if(pos.t>=a[j].t){
				cnt+=a[j].t;
				a[j].t=0;
				j++;
			}else{
				cnt+=pos.t;
				a[j].t-=pos.t;
				pos=st.top();
				st.pop();
			}
		}
	}
	cout<<cnt;
	return 0;
} 
