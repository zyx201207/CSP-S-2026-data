//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7
#include<bits/stdc++.h>
using namespace std;
int m,n,a[500050],mdi,maxa=500050,z=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int s=0;
		for(int j=0;j<n;j++){
			s+=a[j]-a[i];
		}if(s<0){
			s=s*-1;
		}
		if(maxa>s){
			mdi=i;
			maxa=s;
		}
	}//a[mdi]适合搓能量球
	for(int i=mdi;i>=0;i--){
		//此处排序？
		if(m<=0){
			break;
		}
		m-=a[mdi]-a[i];
		a[i]+=a[mdi]-a[i];
		//35 35行未考虑m此时为负的情况 
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[mdi]){
			z++;
		}
	}cout<<z;
	return 0;
}
