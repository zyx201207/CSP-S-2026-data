#include <bits/stdc++.h>
using namespace std;
struct stu{
	int n;
	char ch;
};
int min(long long x,long long y){
	if(x<y){
		return x;
	}else{
		return y;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	stu a[200010];
	for(int t=1;t<=n;t++){
		cin>>a[t].n>>a[t].ch;
	}
	long long l=1,r=n,z=0,q=0;
	while(l!=r){
		if(a[l].ch!=a[r].ch){
			q=min(a[l].n,a[r].n);
			z+=q;
			a[l].n-=q;
			a[r].n-=q;
			if(a[l].n==0){
				l++;
			}else{
				r--;
			}
		}else{
			q=min(a[l].n,a[r].n);
			a[l].n-=q;
			a[r].n-=q;
			if(a[l].n==0){
				l++;
			}else{
				r--;
			}
			cout<<l<<" "<<r<<endl;
		}
	}
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
