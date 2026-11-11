#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,lin,sta,fei,n;
	int w[500009]={};
	int k[509]={};
	int a[509][500009]={};
	int t[509][500009]={};
	cin>>c>>lin>>sta>>fei>>n;
	for(int i=1;i<=sta;i++){
		cin>>w[i];
	}
	for(int i=1;i<=lin;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			t[i][a[i][j]]=t[i][j];
			t[i][j]=0;
		}
	}
	int begin_,end_,ans=0;
	for(int i=1;i<=n;i++){
		cin>>begin_>>end_;
		ans+=w[begin_];
		
		if(end_>begin_){
			while(begin_!=end_){
				int min_=1000000000;
				for(int j=1;j<=lin;j++){
					if(min_>t[j][begin_]&&t[j][begin_+1]!=0){
						min_=t[j][begin_];
					}
				}
				ans+=min_;
				begin_++;
			}
			cout<<ans;
			return 0;
		}
		else{
			while(begin_!=end_){
				int min_=1000000000;
				for(int j=1;j<=lin;j++){
					if(min_>t[j][begin_]&&t[j][begin_-1]!=0){
						min_=t[j][begin_];
					}
				}
				ans+=min_;
				begin_--;
			}
			cout<<ans;
			return 0;
		}
		
		
	}
	
	return 0;
} 
