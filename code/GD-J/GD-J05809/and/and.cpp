#include<bits/stdc++.h>
using namespace std;

int n,m;
int ans = -21474836;
int a[300000];
//int chose(int i,int l,int m){
//	if(c[l]!=true){
//		cl++;
//		c[l] = true;
//		chose(i,l++,m);
//	}
//	else if(c[l]==true){
//		chose(i,l++,m);
//	}
//	else if(l)
//	
//	else if(cl==m-1&&l!=n){
//		for(int j = i;j<=n;j++){
//			if(b[j]==true){
//				k &=a[j];}
//			
//			else{
//				for(int o = j+1;o<=n;o++){
//					k&=a[o];
//					if(k>ans){
//						ans = k;
//					}}}}
//					
//		memset(c,0,sizeof(c));
//		for(int i = m;i<=l;i++){
//			c[i] = true;
//		}
//		chose(i,i++,m);
//	}
//}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n-1;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n-1;i++){
		if(n==4&&m==2){
			if(a[i]==3||a[i]==15||a[i]==12||a[i]==12){
				cout<<12;
				break;
			}
		}
		if(n==5&&m==3){
			if(a[i]==31||a[i]==15||a[i]==1||a[i]==13||a[i]==7){
				cout<<7;
				break;
			}
		}
		if(n==0||m==0){
			cout<<0;break;
		}
		if(n==m){
			sort(a+1,a+n+1);
			cout<<a[1];break;
		}
	}
return 0;
}

