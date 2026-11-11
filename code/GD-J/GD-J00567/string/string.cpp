//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//struct node{
//	int x,xs,xz;
//	char y;
//};
//node a[300000],l[300000],r[300000],zh;
//int n,cnt,t1t,lcn=1,rcn=1,b[300000],lz=1,rz=1,ase;
//signed main(){
//	cin.tie(0);
//	cout.tie(0);
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].x>>a[i].y;
//		a[i].xs=cnt+1;
//		cnt+=a[i].x;
//		a[i].xz=cnt;
//	}
//	if(cnt%2==0){
//		t1t=0;
//	}else{
//		t1t=1;
//	}
//	int til,tir;
//	for(int i=1;i<=n;i++){
//		if(a[i].xz<=cnt/2){
//			l[lcn].x=a[i].x;
//			l[lcn].xs=a[i].xs;
//			l[lcn].xz=a[i].xz;
//			l[lcn].y=a[i].y;
//			lcn++;
//			b[i]=1;
//		}else{
//			til=i;
//			break;
//		}
//	}
//	for(int i=n;i>=til;i--){
//		if(a[i].xs>=cnt/2){
//			r[rcn].x=a[i].x;
//			r[rcn].xs=n-a[i].xz+1;
//			r[rcn].xz=n-a[i].xs+1;
//			r[rcn].y=a[i].y;
//			rcn++;
//			b[i]=1;
//		}else{
//			tir=i;
//			break;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		if(b[i]==0){
//			l[lcn].x=cnt/2-a[i].xs;
//			l[lcn].xs=a[i].xs;
//			l[lcn].xz=cnt/2;
//			l[lcn].y=a[i].y;
//			r[rcn].x=a[i].xz-cnt/2;
//			r[rcn].xs=n-a[i].xz+1;
//			r[rcn].xz=cnt/2+1;
//			r[rcn].y=a[i].y;
//		}
//	}
//	if(t1t==0){
//		while(1){
//			if(l[lz].x>r[rz].x){
//				if(l[lz].y!=r[rz].y){
//					ase+=r[rz].x;
//				}
//				l[lz].x-=r[rz].x;
//				rz++;
//			}else if(l[lz].x<r[rz].x){
//				if(l[lz].y!=r[rz].y){
//					ase+=l[lz].x;
//				}
//				r[rz].x-=l[lz].x;
//				lz++;
//			}else{
//				if(l[lz].y!=r[rz].y){
//					ase+=l[lz].x;
//				}
//				rz++;
//				lz++;
//			}
//		}
//	}
//	cout<<ase;
//	return 0;
//}
//aabbc
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt,cnt2;
char a[4000000];
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int t1;
		char t2;
		cin>>t1>>t2;
		if(t1*n>=3000000){
			return 0;
		}
		for(int j=1;j<=t1;j++){
			cnt++;
			a[cnt]=t2;
		}
	}
	cnt2=0;
	for(int i=1;i<=cnt/2;i++){
		if(a[i]!=a[cnt-i+1]){
			cnt2++;
		}
	}
	cout<<cnt2;
	return 0;
}
