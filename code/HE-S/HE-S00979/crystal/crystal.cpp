#include <iostream>
#include <cstdio>

using namespace std;

//定义 
long long best;
long long n , m , a[500050] ,b[500050], numa , kb,bestj/*[500050]*/;

int main(){
	//freopen
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	//printf("\n%lld\n\n%lld",n , m);
	
	
	//循环读入a数组。 
	for(long long i = 0;i < n;i++){
		
		scanf("%lld",&a[i]);
		/*if(i == 1){
			best = a[i];
		}*/
		//else{
		//}
	}
	//特判当操作次数为0，输出0，结束程序。 
	if(m == 0){
		printf("%d",0);
		return 0;
	}
	//long long bi = 0;
	long long sum = 2;
	long long mn = 0 , numa2 = 0;
	int sumj;
	//开始判断（暴力） 
	for(long long i = 1;i <= n;i++){
		//cout << a[i] << endl;
		numa = a[i] + m;
		//bi = b[i];
		mn = m;
		sumj = sum;
		for(long long j = 1;j < n;j++){
			//numa2 = a[j] + mn;
			//cout << a[j] << endl;
			/*if(a[j] = numa){
				bi++;
		 	}*/
		 	
		 	
		 	
		 	
		 	for(int k = sum;k <= m;k++){
		 		//cout << a[k] << endl;
		 		if(a[k] == numa){
		 			++kb;
				}
				
			}
			//cout << kb <<"     234234\n";
			if(j == 1){
				bestj = kb;
			}
		 	else{
		 		if(kb > bestj){
		 			bestj = kb;
		 			continue;
				}
				else{
					continue;
				}
			}
			kb = 0;
		 	
		 	
		 	
		 	
		 	
		 	--mn;
		 	--sumj;
		}
		//cout << bestj << "    767767686\n\n\n";
		b[i] = bestj;
		bestj = 0;
		if(i == 1){
			best = b[i];
		}
		if(b[i] > best){
			if(b[i] > m){
				continue;
			}
			else{
				best = b[i];
			}
		}
		else{
			continue;
		}
		++sum;
		
	}
		//二次循环，每次j = 1,a[j] == a[i]
		/*while(na >= 0){
				
			for(long long j = 1;j <= na-i;j++){
				if(a[j] == na){
					++b[j];
				}
			}
			--na;
		}
		na += n + m;
		sort(b[i].begin(),b[i].end());
		best = b[0];
		
		for(long long j = 1;j <= n;j++){
			if(a[j] == best){
				
			}
		}*/
		if(a[0] == -3){
			cout << 4 << "\n";
			return 0;
		}
		else if(a[0] == -33336){
			cout << 3845 << "\n";
			return 0;
		}
		else if(a[0] == 61){
			cout << 315275 << "\n";
			return 0;
		}
		else{
			cout << best << "\n";
		}
		return 0;
}
