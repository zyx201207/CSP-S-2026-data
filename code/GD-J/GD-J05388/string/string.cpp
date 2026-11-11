#include<bits/stdc++.h>
using namespace std;
long long ans,n,sum,sum2,c;
bool f;
struct str{
	long long l;
	char x;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].x;
		sum+=a[i].l;
	}
	if(sum%2){
		sum=sum/2+1;
		f=1;
	}
	else{
		sum/=2;
	}
	for(int i=1;i<=n;i++){
		sum2+=a[i].l;
		if(sum2>=sum){
			int cha=sum2-sum;
			for(int j=n+1;j>i+1;j--){
				a[j].l=a[j-1].l;
				a[j].x=a[j-1].x;
			}
			n++;
			c=i;
			a[i].l=f?a[i].l-cha-1:a[i].l-cha,a[i+1].l=cha,a[i+1].x=a[i].x;
			break;
		}
	}
	for(int i=c,j=c+1;i>0,j<=n;){
		if(a[i].l==a[j].l){
			if(a[i].x!=a[j].x){
				ans+=a[i].l;
			}
			i--,j++;
		}
		else if(a[i].l>a[j].l){
			if(a[i].x!=a[j].x){
				ans+=a[j].l;
			}
			a[i].l-=a[j].l;
			j++;
		}
		else{
			if(a[i].x!=a[j].x){
				ans+=a[i].l;
			}
			a[j].l-=a[i].l;
			i--;
		}
	}
	cout<<ans;
	return 0;
}
