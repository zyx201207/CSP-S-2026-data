#include<bits/stdc++.h>
using namespace std;
struct p{
	long long a1;
	char s1;
}a[200005];	
long long sum;
int n;

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i].a1>>a[i].s1;
}
int l=1,r=n;
while(r-l>0){
	if(a[l].s1==a[r].s1){
    if(a[l].a1>a[r].a1){
	a[l].a1-=a[r].a1;
	r--;
	}
	else if(a[l].a1<a[r].a1){
	a[r].a1-=a[l].a1;
	l++;
	}
	else{
		l++;
		r--;}			
}
    else{
    if(a[l].a1>a[r].a1){
	a[l].a1-=a[r].a1;
	sum+=a[r].a1;
	r--;
	}
	else if(a[l].a1<a[r].a1){
	a[r].a1-=a[l].a1;
	sum+=a[l].a1;
	l++;
	}
	else{
		sum+=a[l].a1;
		l++;
		r--;}			
}
}
cout<<sum;
fclose(stdin);
fclose(stdout);
return 0;
}
