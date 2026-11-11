#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long t;
	char c;
}a[200010];
long long l,r,n,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i].t,&a[i].c);
	}
	l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].t>=a[r].t){
				a[l].t-=a[r].t;
				r--;
			}
			else{
				a[r].t-=a[l].t;
				l++;
			}
		}
		else{
			if(a[l].t>=a[r].t){
				a[r].c=a[l].c;
				cnt+=a[r].t;
				a[l].t-=a[r].t;
				r--;
			}
			else{
				a[l].c=a[r].c;
				cnt+=a[l].t;
				a[r].t-=a[l].t;
				l++;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
