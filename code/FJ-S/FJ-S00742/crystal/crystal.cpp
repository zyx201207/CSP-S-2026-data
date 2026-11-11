#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

int n;
long long m;
long long a[N];
long long sum[N];

void solvea(){
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(m-i>=0){
			m-=i;
			cnt++;
		}else{
			break;
		}
	}
	printf("%d",cnt);
}

void solveb(){
	long long c = a[2]-a[1];
	if(c == 0){
		printf("%d",n);
		return;
	}else{
		printf("%d",m/c+1);
	}
}

void solvec(){
	int tmp = m;
	int cnt = 1;
	for(int rd = 1;rd<=n;rd++){
		tmp = m;
		for(int i = rd-1;i>=1;i--){
			if(tmp-(a[rd]-a[i])>=0){
				tmp-=a[rd]-a[i];
				if(i == 1){
					cnt = max(cnt,rd);
				}
			}else{
				cnt = max(cnt,rd-i);
				break;
			}
		}
	}
	printf("%d",cnt);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    
    bool isa = true,isb = true;
    long long lst = 0;
    for(int i = 1;i<=n;i++){
    	scanf("%lld",&a[i]);
    	//A and B 
    	if(a[i]!=i){
    		isa = false;
		}
		if(i == 2){
			lst = a[i]-a[i-1];
		}else{
			if(i>2){
				if(a[i]-a[i-1]!=lst){
					isb = false;
				}
			}
		}
	}
	if(isa){
		solvea();
		return 0;
	}
	if(isb){
		solveb();
		return 0;
	}
	sort(a+1,a+n+1);
	//n<=5000
	if(n<=5000){
		solvec();
		return 0;
	}
	//all
	for(int i = 2;i<=n;i++){
		sum[i] = sum[i-1]+a[i]-a[i-1];
	}
	int ans = 1;
    int q[N],h = 1,t = 1;
    q[1] = n;
    long long s = 0;
    for(int i = n-1;i>=1;i--){
    	q[++t] = i;
    	s+=sum[q[h]]-sum[i];
    	if(s>m){
    		while(s>m && h<=t){
    			int x = q[h];
    			h++;
    			int len = t-h+1;
    			s-=len*(a[x]-a[q[h]]);
			}
		}
		ans = max(ans,t-h+1);
	}
	printf("%d",ans);
	
	return 0;
}
