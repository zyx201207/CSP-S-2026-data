#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r,s,a[200001];
char c[200001];
/*
2
2 a
3 a
*/
/*
3
2 a
2 b
1 c
*/
/*
6
100 a
100 a
100 a
100 b
100 b
100 b
*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>a[1]>>c[1];
	for(int i=2;i<=n;i++){
		long long ls;char ls2;
		cin>>ls>>ls2;
		if(ls2==c[i-1]){
			a[i-1]+=ls;
			n--;i--;
		}
		else{
			a[i]=ls;
			c[i]=ls2;
		}
	}
	r=n;
	while(l<r){
		bool ls=(c[l]!=c[r]);
		if(a[l]==a[r]){
			l++;r--;
			s+=a[l]*ls;
		}
		else if(a[l]>a[r]){
			a[l]-=a[r];a[r]=0;
			s+=(a[l]-a[r])*ls;
			r--;
		}
		else if(a[l]<a[r]){
			a[r]-=a[l];a[l]=0;
			s+=(a[r]-a[l])*ls;
			l++;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//这代码无疑是过不了的，放弃治疗 
//11:24 iu我去，还能蒸 

//craft
