#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[3];
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]<a[i-1]) flag=0;
	}
	if(m<=2){
		
		for(long long oo=1;oo<=n;oo++){
			queue <long long> q;
			q.push(a[oo]);
			for(long long i=oo+1;i<=n;i++){
				if(q.front()==a[i]){
					q.pop();
					q.pop();
					q.push(a[i]);
				}else if(q.back()!=a[i]){
					q.push(a[i]);
				}
			}
			if(q.front()==q.back()){
				b[q.front()]++;	
			}else{
				b[1]++;
				b[2]++;
			}
		}
		cout << b[1] << " " << b[2];
		
	}else if(flag){
		long long sum=1;
		for(long long i=2;i<=n;i++){
			if(a[i]!=a[i-1]) cout << sum << " ";
			sum++;
		}
		cout << sum;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
