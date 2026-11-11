#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[300005]={};
int ti[300005]={};
deque<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		q.clear();
		for(int i=n;i>=k;i--){
			q.push_back(a[i]);
//			ti[a[i]]++;
			bool b=0;
			int x=0;//É¾³ý´ÎÊý 
			for(int j=0;j<q.size()-1;j++){
				if(q[j]==a[i]){
					b=1;
				}
				if(b) x++;
			}
	//		printf("%d %d\n",b,x);
			for(int j=1;j<=x;j++){
				int t=q.back();
//				ti[t]--;
				q.pop_back();
			} 
//			if(b) q.push_back(a[i]);	
//		for(int j=0;j<q.size();j++){
//			printf("%d",q[j]);
//		}
//		printf("\n");
		}
		for(int i=0;i<q.size();i++) ti[q[i]]++;	
	}

	for(int i=1;i<=m;i++){
		printf("%d ",ti[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
