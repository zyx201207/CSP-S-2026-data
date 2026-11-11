#include <bits/stdc++.h>
using namespace std;
struct kk{
	long long a;
	string c;
};


kk a[114514];
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	long long cnt=0,p1=1,p2=n;
	if (n%2==1){
	for (int i=1;i<=n/2+1;i++){
		if (a[p1].c!=a[p2].c){
			cnt+=abs(a[p1].a-a[p2].a);
			if (a[p1].a>a[p2].a){
				a[p1].a-=a[p2].a;
				p2--;
			}
			else if (a[p1].a<a[p2].a){
				a[p2].a-=a[p1].a;
				p1--;
			}
			else{
				cnt+=abs(a[p1].a);
				p1--,p2--;
			}
//			cout<<abs(a[i].a-a[n-i+1].a)<<" ";
		}
		else{
			if (a[p1].a>a[p2].a){
				a[p1].a-=a[p2].a;
				p2--;
			}
			else if (a[p1].a<a[p2].a){
				a[p2].a-=a[p1].a;
				p1--;
			}
			else p1--,p2--;
		}
	}
}
	else{
		for (int i=1;i<=n/2;i++){
		if (a[p1].c!=a[p2].c){
			cnt+=abs(a[p1].a-a[p2].a);
			if (a[p1].a>a[p2].a){
				a[p1].a-=a[p2].a;
				p2--;
			}
			else if (a[p1].a<a[p2].a){
				a[p2].a-=a[p1].a;
				p1--;
			}
			else{
				cnt+=abs(a[p1].a);
				p1--,p2--;
			}
//			cout<<abs(a[i].a-a[n-i+1].a)<<" ";
		}
		else{
			if (a[p1].a>a[p2].a){
				a[p1].a-=a[p2].a;
				p2--;
			}
			else if (a[p1].a<a[p2].a){
				a[p2].a-=a[p1].a;
				p1--;
			}
			else p1--,p2--;
		}
	}
	}
//	cout<<'\n';
	cout<<cnt;
	return 0;
}
//6 
//1000000000 a 
//1000000000 a 
//1000000000 a 
//1000000000 b 
//1000000000 b 
//1000000000 b
