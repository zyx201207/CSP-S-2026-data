#include<bits/stdc++.h>
using namespace std;
struct pp{
	long long int a;
	char b;
}a[200005];
int n,o;
long long int c,d,e;
bool f=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].a);
		cin>>a[i].b;
		c+=a[i].a;
	}
	if(c%2==0)
		c/=2;
	else{
		f=1;
		c=c/2+1;
	}
	for(int i=1;i<=n;i++){
		d+=a[i].a;
		if(c<=d){
			o=i;
			d=c-d+a[o].a;
			break;
		}
	}int i=0,j=0;
	while(o+i<=n&&o-j>0){
		if(f&&i==0&&j==0){
			d--;
			a[o].a--;
		}
		if(i==0&&j==0){
			if(d*2<a[o].a){
				i=0;
				j=1;
				a[o].a-=2*d;
			}else if(d*2==a[o].a){
				j=1;
				i=1;
			}else{
				i=1;
				j=0;
				a[o].a=d*2-a[o].a;
			}
		}
		if(a[o+i].b==a[o-j].b){
			if(a[o+i].a>a[o-j].a){
				a[o+i].a-=a[o-j].a;
				j++;
			}
			else{
				a[o-j].a-=a[o+i].a;
				if(a[o-j].a==0)j++;
				i++;
			}
		}
		else{
			if(a[o+i].a>a[o-j].a){
				e+=a[o-j].a;
				a[o+i].a-=a[o-j].a;
				j++;
			}else{
				e+=a[o+i].a;
				a[o-j].a-=a[o+i].a;
				if(a[o-j].a==0)
					j++;
				i++;
			}
		}
	}
	cout<<e;
	return 0;
}
