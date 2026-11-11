#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],cnt[N],f[M];
deque<int> q;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    for(int k=1;k<=n;k++){
    	q.clear();
    	memset(f,0,sizeof(f));
    	for(int i=k;i<=n;i++){
	//	cout<<"*** ";
		if(q.empty()) {
			q.push_back(a[i]);
		
		//	cout<<"f";
			
		}
		else if(f[a[i]]==0){
			q.push_back(a[i]);
		
		//	cout<<"g";
		}else{
			while(!q.empty()){
				int t=q.back();
				q.pop_back();
				f[t]--;
				if(f[a[i]]==0) break;
	//			cout<<"h ";
			}
//		cout<<"***";
	       
        q.push_back(a[i]);
			
		}
		 f[a[i]]++;
//		deque<int> k=q;
//        cout<<"^";
//		while(!k.empty()){
//			cout<<k.front()<<' ';
//			k.pop_front();
//		}
//      	cnt[a[i]]++;
        
//        for(int j=1;j<=m;j++){
//        	if(f[j]==1) cnt[j]=i;
//		}
//		
//		for(int i=1;i<=m;i++){
//			cout<<cnt[i]<<" ";
//		}cout<<endl;
		
      }
      for(int i=1;i<=m;i++){
      	if(f[i]==1) cnt[i]++;
	  }
}
//	cout<<"kkk ";
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
} 
