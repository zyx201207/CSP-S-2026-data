#include<bits/stdc++.h>
using namespace std;
long long a[100001],n,summ=0,x=0,s1=1,s4=0;
char c[100001];
long long abcd(long long s){
	long long su=0;
	for(int i=1;i<=n;i++){
		if(s<=su){
			return i-1;
		}else{
			su+=a[i];
		}
	}return n;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		summ+=a[i];
	}
	while(s1<=(summ+1)/2){
		long long s2=0,s3=0;
		for(int i=1;i<=n;i++){
			if(i<=abcd(s1)){
				s2+=a[i];
			}else if(i>=abcd(summ-s1+1)){
				s3+=a[i];
			}
		}
		if(s2<=s3){
			if(c[abcd(s1)]!=c[abcd(summ-s1+1)]){
				x+=s2-s4;
			}s4=s2;s1+=a[abcd(s1)];
		}else{
			if(c[abcd(s1)]!=c[abcd(summ-s1+1)]){
				x+=s3-s4;
			}s4=s3;s1+=a[abcd(summ-s1+1)];
		};
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
