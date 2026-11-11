#include<bits/stdc++.h>
using namespace std;
int ma=0;
bool and1(int a,int b){
	return a&b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==n){
		ma=a[0];
		for(int i=1;i<n;i++)ma=and1(ma,a[i]);
		cout<<ma;
	}
	else if(m==1)cout<<*max_element(a,a+n);
	else if(m==2){
		for(int i=0;i<n;i++){
			int t=a[i];
			for(int j=i+1;j<m+1;j++){
				t=and1(t,a[j]);
			}
			ma=max(ma,t);
		}
		cout<<ma;
	}
	else if(m==n-1){
		int t=a[1];
		for(int i=1;i<n;i++)t=and1(t,a[i]);
		ma=max(ma,t);
		for(int i=1;i<n;i++){
			t=a[0];
			for(int j=1;j<n;j++){
				if(j!=i)t=and1(t,a[j]);
			}
			ma=max(t,ma);
		}
		cout<<ma;
	}
	else{
		int x,y;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<m+1;j++){
				int t=(a[i]&a[j]);
				if(ma<t){
					x=i;
					y=j;
					ma=t;
				}
			}
		}
		a[x]=-1;
		a[y]=-1;
		int mm=m-2,ma2=0;
		while(mm>0){
			int nn;
			for(int i=0;i<n;i++){
				int xx=ma;
				if(a[i]!=-1){
					xx=(xx&a[i]);
					if(ma2<xx){
						nn=i;
						ma2=xx;
					}
				}
			}
			a[nn]=-1;
			mm--;
		}
		cout<<ma2;
	}
	return 0;
} 
