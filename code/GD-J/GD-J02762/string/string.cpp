
#include<bits/stdc++.h> 
using namespace std;
string a;
int n;
long long b[100005],bb;
long long x,jia;

bool f(long long xx){
	jia=0;
	long long yy=xx;
	long long i=0;
	int l,r; 
	while(1){
		i++;
		if(xx>=b[i]){
			xx-=b[i];
		}else{
			l=i-1; 
			jia=b[i]-xx;
			break;
		}
	}
	i=0;
	while(1){
		if(yy>=b[bb-i]){
			yy-=b[bb-i];
		}else{
			r=bb-i-1;
			jia=min(jia,b[bb-i]-yy);
			break;
		}
		i++;
	}
	//cout<<l<<" "<<r<<" "<<jia<<" ";
	if(a[l]==a[r]){//cout<<"+0"<<endl;
		return 0;
	}
	//cout<<"+1"<<endl;
	return 1;
}
int main(){
	/*
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//*/
	a="";
	cin>>n;
	x=0;
	bb=0;
	for(int i=1;i<=n;i++){
		long long p;
		char q;
		cin>>p;
		x+=p;
		b[i]=p;
		cin>>q;
		a+=q;
	}bb=n;
	long long sum=0;
	for(long long i=0;i*2<x;i++){
		if(f(i)){
			sum+=(jia);
		}
		i+=jia-1;
		//cout<<jia<<endl;
	}
	cout<<endl;
	cout<<sum;
	/*
	fclose(stdin);
	fclose(stdout);
	//*/
	return 0;
}
/*
5
3 a
1 b
1 a
1 c
1 b
abacb
aaabacb
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/

