#include<bits/stdc++.h>
using namespace std;
int head,tail,n,a[200005]={0};
long long s=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	head=1;
	tail=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(head<tail){
		if(c[head]==c[tail]){
			if(a[head]>a[tail]){
				a[head]-=a[tail];
				tail--;
			}
			if(a[head]==a[tail]){
				head++;
				tail--;
			}
			if(a[head]<a[tail]){
				a[tail]-=a[head];
				head++;
			}
		}else{
			if(a[head]>a[tail]){
				a[head]-=a[tail];
				s+=a[tail];
				tail--;
			}
			if(a[head]==a[tail]){
				s+=a[tail];
				head++;
				tail--;
			}
			if(a[head]<a[tail]){
				a[tail]-=a[head];
				s+=a[head];
				head++;
			}
		}
	}
	cout<<s;
	return 0;
}
