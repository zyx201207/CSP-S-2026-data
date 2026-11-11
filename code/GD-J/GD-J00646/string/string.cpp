//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=200010;
//struct node{long long cnt=0;char c='A';}a[maxn];
//int main(){
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
////	freopen("string.in","r",stdin);
////	freopen("string.out","w",stdout);
////É¾×¢ÊÍ
//	int n=0,m;cin>>m;
//	for(int i=1;i<=m;i++){
//		long long val;char ch;cin>>val>>ch;
//		if(ch==a[n].c)a[n].cnt+=val;
//		else{
//			n+=1;
//			a[n].cnt=val,a[n].c=ch;
//		}
//	}
//	long long S=0,df=0;
//	for(int i=1;i<=n;i++)S+=a[i].cnt;
//	
//	if(S&1==1){
//		
//		long long mid=(S-1)/2+1;
//		int nw=0;long long dfr=0;
//		for(int i=1;i<=n;i++){
//			if(mid>a[i].cnt)mid-=a[i].cnt;
//			else{
//				nw=i,dfr=mid-1;
//				break;
//			}
//		}
//		long long l=0,r=0;
//		int lid=0,rid=n+1;
//		while(lid<nw&&nw<rid){
//			if(l==0)l=a[++lid].cnt;
//			if(r==0)r=a[--rid].cnt;
//			
//			if(lid>=nw||nw>=rid)break;
//			long long jp=min(l,r);
//			if(jp==0)break;
//			if(a[lid].c!=a[rid].c)df+=jp;
//			l-=jp,r-=jp;
//		}
//		if(lid==nw&&nw==rid)df+=0;
//		else if(lid==nw){
//			if(a[nw].c!=a[rid].c)df+=min(dfr,r);
//		}else if(rid==nw){
//			if(a[lid].c!=a[nw].c)df+=min(l,r-dfr-1);
//		}
//		cout<<df<<'\n';
//	}else{
//		long long mid=S/2;
//		int nw=0;long long dfr=0;
//		for(int i=1;i<=n;i++){
//			if(mid>a[i].cnt)mid-=a[i].cnt;
//			else{
//				nw=i,dfr=mid;
//				break;
//			}
//		}
//		for(int i=n+2;i>nw+1;i--)a[i]=a[i-2];
//		a[nw+2].c=a[nw].c,a[nw+2].cnt=a[nw].cnt-dfr;
//		a[nw+1].c='#',a[nw+1].cnt=1;
//		a[nw].cnt=dfr;
//		
//		
//		////////
//		mid=(S-1)/2+1;
//		nw=0,dfr=0;
//		for(int i=1;i<=n;i++){
//			if(mid>a[i].cnt)mid-=a[i].cnt;
//			else{
//				nw=i,dfr=mid-1;
//				break;
//			}
//		}
//		long long l=0,r=0;
//		int lid=0,rid=n+1;
//		while(lid<nw&&nw<rid){
//			while(l==0)l=a[++lid].cnt;
//			while(r==0)r=a[--rid].cnt;
//			
//			if(lid>=nw||nw>=rid)break;
//			long long jp=min(l,r);
//			if(jp==0)break;
//			if(a[lid].c!=a[rid].c)df+=jp;
//			l-=jp,r-=jp;
//		}
//		if(lid==nw&&nw==rid)df+=0;
//		else if(lid==nw){
//			if(a[nw].c!=a[rid].c)df+=min(dfr,r);
//		}else if(rid==nw){
//			if(a[lid].c!=a[nw].c)df+=min(l,r-dfr-1);
//		}
//		cout<<df<<'\n';
//	}
//	return 0;
//} 

/*
3
2 a
2 b
1 c
*/



#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
struct node{long long cnt=0;char c='A';}a[maxn];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//É¾×¢ÊÍ
	int n=0,m;cin>>m;
	for(int i=1;i<=m;i++){
		long long val;char ch;cin>>val>>ch;
		if(ch==a[n].c)a[n].cnt+=val;
		else{
			n+=1;
			a[n].cnt=val,a[n].c=ch;
		}
	}
	long long S=0,df=0;
	for(int i=1;i<=n;i++)S+=a[i].cnt;
	if(S&1==1){
		
		long long mid=(S-1)/2+1;
		int nw=0;long long dfr=0;
		for(int i=1;i<=n;i++){
			if(mid>a[i].cnt)mid-=a[i].cnt;
			else{
				nw=i,dfr=mid-1;
				break;
			}
		}
		long long l=0,r=0;
		int lid=0,rid=n+1;
		while(lid<nw&&nw<rid){
			if(l==0)l=a[++lid].cnt;
			if(r==0)r=a[--rid].cnt;
			
			if(lid>=nw||nw>=rid)break;
			long long jp=min(l,r);
			if(jp==0)break;
			if(a[lid].c!=a[rid].c)df+=jp;
			l-=jp,r-=jp;
		}
		if(lid==nw&&nw==rid)df+=0;
		else if(lid==nw){
			if(a[nw].c!=a[rid].c)df+=min(dfr,r);
		}else if(rid==nw){
			if(a[lid].c!=a[nw].c)df+=min(l,r-dfr-1);
		}
		cout<<df<<'\n';
	}else{
		long long mid=S/2;
		int nw=0;long long dfr=0;
		for(int i=1;i<=n;i++){
			if(mid>a[i].cnt)mid-=a[i].cnt;
			else{
				nw=i,dfr=mid;
				break;
			}
		}
		long long l=0,r=0;
		int lid=0,rid=n+1;
		while(lid<nw&&nw<rid){
			if(l==0)l=a[++lid].cnt;
			if(r==0)r=a[--rid].cnt;
			
			if(lid>=nw||nw>=rid)break;
			long long jp=min(l,r);
			if(jp==0)break;
			if(a[lid].c!=a[rid].c)df+=jp;
			l-=jp,r-=jp;
		}
		if(lid==nw&&nw==rid)df+=0;
		else if(lid==nw){
			if(a[nw].c!=a[rid].c)df+=min(dfr,r);
		}else if(rid==nw){
			if(a[lid].c!=a[nw].c)df+=min(l,r-dfr-1);
		}
		cout<<df<<'\n';
	}
	
	 
	
	
	
	
	
	
	
	return 0;
} 
//
///*
//3
//2 a
//2 b
//1 c
//*/
