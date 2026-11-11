#include<bits/stdc++.h>
using namespace std;

int n;
long long l[200005];
char s[200005];
long long sum;
long long pl,pr,lcount,rcount;
long long countc,lstep,rstep;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		
		cin>>l[i];
		cin>>s[i];
		sum += l[i];
		
	}
	
	pr = n-1;
	rcount = l[pr];
	rstep = sum;
	while(lstep < sum/2 && rstep > (sum-1)/2){
		
		while(s[pl]!=s[pr] && (lstep < sum/2 && rstep > (sum-1)/2)){
			long long pinuocao = min(min(l[pl]-lcount,rcount),min(sum/2-lstep,rstep-(sum-1)/2));
			countc+=pinuocao;
			lcount+=pinuocao;
			lstep+=pinuocao;
			rcount-=pinuocao;
			rstep-=pinuocao;		
			if(lcount >= l[pl]){
				lcount = 0;
				pl++;
			}
			if(rcount <= 0){
				pr--;
				rcount = l[pr];
			}
		}
		long long pinuocao = min(min(l[pl]-lcount,rcount),min(sum/2-lstep,rstep-(sum-1)/2));
		lcount+=pinuocao;
		lstep+=pinuocao;
		rcount-=pinuocao;
		rstep-=pinuocao;
		if(lcount >= l[pl]){
			lcount = 0;
			pl++;
		}
		if(rcount <= 0){
			pr--;
			rcount = l[pr];
		}
		
		
	}
	
	
	cout<<countc<<"\n";
	
	return 0;
	
}
