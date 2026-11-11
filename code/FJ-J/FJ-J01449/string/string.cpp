#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long a;
	char s;
}a[200005],b[200005];
long long l;
long long ans;
int pos,flag,vis;
long long num,i;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].s;
		b[i].a=a[i].a;
		b[i].s=a[i].s;
		l+=a[i].a;
	}
	for(long long i=0;i<=l;i++){
		pos++;
		if(num<=(l+1)/2)num+=a[pos].a;
		if(flag==0&&num>(l+1)/2){
			b[pos].a-=(num-(l+1)/2);
			flag=1;
			vis=pos;
		}
		else{
			if(flag==1){
				b[pos].a=b[vis-(pos-vis)].a;
				b[pos].s=b[vis-(pos-vis)].s;
			}
		}
		i+=b[pos].a;
	}
	int p1=1,p2=1;
	while(i<=l){
		if(p1>n||p2>pos)break;
		if(a[p1].a==b[p2].a){
			i+=a[p1].a;
			if(a[p1].s!=b[p2].s){
				ans+=a[p1].a;
			}
			a[p1].a=0;
			b[p2].a=0;
			p1++;
			p2++;
		}
		else{
			if(a[p1].a<b[p2].a){
				i+=a[p1].a;
				if(a[p1].s!=b[p2].s){
					ans+=a[p1].a;
				}
				a[p1].a=0;
				b[p2].a-=a[p1].a;
				p1++;
			}
			if(a[p1].a>b[p2].a){
				i+=b[p2].a;
				if(a[p1].s!=b[p2].s){
					ans+=b[p2].a;
				}
				a[p1].a-=b[p2].a;
				b[p2].a=0;
				p2++;
			}
		}
	}
	cout<<ans;
	return 0;
}

