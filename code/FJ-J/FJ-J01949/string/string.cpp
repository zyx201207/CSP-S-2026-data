#include<bits/stdc++.h>
using namespace  std;

long long n,ans,sum;
struct f{
	long long age;
	char s;
}a[200005];

long long big(long long aa,long long bb){
	if(aa>=bb){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].age>>a[i].s;
		sum+=a[i].age;
	}
	if(sum&1){
		sum=sum/2+1;
		long long h=0;
		for(long long i=1;i<=n;i++){
			h+=a[i].age;
			if(h>=sum){
				a[i].age--;
				break;
			}
		}
	}
	long long l=1,r=n;
	while(r-l>0){
		long long hh=big(a[l].age,a[r].age);
		if(a[l].s==a[r].s){
			if(a[l].age==a[r].age){
				l++;
				r--;
			}else if(hh){
				a[l].age-=a[r].age;
				r--;
			}else{
				a[r].age-=a[l].age;
				l++;
			}
		}else{
			if(a[l].age==a[r].age){
				ans+=a[l].age;
//				cout<<1;
				l++;
				r--;
			}else if(hh){
//				cout<<r<<"  ";
				a[l].age-=a[r].age;
				ans+=a[r].age;
				r--;
			}else{
//				cout<<1;
				a[r].age-=a[l].age;
				ans+=a[l].age;
				l++;
			}
		}
//		cout<<l<<" "<<r<<"  "<<ans<<" ";
//		init();
	}
	cout<<ans;
	return 0;
}
