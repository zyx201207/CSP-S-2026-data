#include<bits/stdc++.h>
using namespace std;

int a[500010],cnt[100000];
int cnt1,cnt2;
int q1,q2;


int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	
	int n,m;
	cin >> n >> m; 
	
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(q1!=a[i] && cnt1!=1){
			q1=a[i];
			cnt1++;
		}
		
		if(q1!=a[i] && cnt2!=1){
			q2=a[i];
			cnt2++;
		}
	}
	
	int k=q1;
	
	
	cnt[q1]=n;
	for(int i=1;i<=n;i++){
		if(a[i]!=k){
			cnt[q2]++;	
		}
		
	}
	if(q1<q2){
		cout << cnt[q1] << " " <<cnt[q2];
	}
	else{
		cout << cnt[q2] << " " <<cnt[q1];
	}
	


	return 0;
} 
