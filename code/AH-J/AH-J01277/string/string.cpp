#include<bits/stdc++.h>
using namespace std;
struct xx{
	long long a;
	char c;

}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	int l=1;
	int r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
            s+=min(a[l].a,a[r].a);
		}
        if(a[l].a<a[r].a){
            a[r].a-=a[l].a;
            a[l].a=0;


            l++;
        }else if(a[l].a>a[r].a){
             a[l].a-=a[r].a;
            a[r].a=0;


            r--;
        }else{
            a[l].a=0;
            a[r].a=0;
            l++;
            r--;
        }
	}
	cout<<s;
    return 0;
}
