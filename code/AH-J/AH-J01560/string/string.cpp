#include<bits/stdc++.h>
using namespace std;
struct node{
	long long ch;
	char zi;
	long long z;
	long long y;
}a[200010];
long long len;
long long l,r;
int li,ri;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ch>>a[i].zi;
		a[i].z=len+1;
		len+=a[i].ch;
		a[i].y=len;
	}
	l=1,r=len;
	li=1,ri=n;
	while(li<ri){
		if(len+1-a[li].y==a[ri].z){
			if(a[li].zi!=a[ri].zi) ans+=a[li].y-l+1;
			li++;
			ri--;
			l=a[li].z;
			r=a[ri].y;
		}else if(len+1-a[li].y>a[ri].z){
			if(a[li].zi!=a[ri].zi) ans+=a[li].y-l+1;
			r=len-a[li].y;
			li++;
			l=a[li].z;
		}else if(len+1-a[li].y<a[ri].z){
			if(a[li].zi!=a[ri].zi) ans+=r-a[ri].z+1;
			l=len+2-a[ri].z;
			ri--;
			r=a[ri].y;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
