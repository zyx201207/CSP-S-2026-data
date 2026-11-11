#include<bits/stdc++.h>
using namespace std;
int m,ansa,a11,n,hn[35][200005],maxx=-1,b[200005],cnt,a[20005];
long long tn[35];
string s;
void mi(){
	tn[0]=1;
	for(int i=1;i<=30;i++){
		tn[i]=tn[i-1]*2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	mi();
	cin>>n>>m;
	
	if(n==m){
		
		for(int i=1;i<=n;i++){
			cin>>a11;
			if(i==1){
				ansa=a11;
			}else{
				ansa&=a11;
			}
		}
		cout<<ansa;
		return 0;
	}else if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			cin>>a11;
			maxx=max(maxx,a11);
		}
		cout<<maxx;
	}else if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else{
		cout<<0;
	}
//	else{
//		for(int i=1;i<=n;i++){
//			cin>>a11;
//			s="";
//			int a1=a11;
//			while(a11>0){
//				char aaa=(a11%2+'0');
//				s=aaa+s;
//				a11/=2;
//				if(aaa=='1'){
//					hn[s.size()-1][0]++;
//					hn[s.size()-1][hn[s.size()-1][0]]=a1;
//					int aaaaa=s.size()-1;
//					maxx=max(maxx,aaaaa);
//				}
//			}
//			
//		}
//		cnt=n;
//		for(int i=maxx;i>=0;i--){
//			if(cnt>=m){
//				break;
//			}else{
//				if(hn[i][0]>=m){
//					for(int j=1;)
//				}
//			}
//		}
//	}
	return 0;
}
