#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool sa = 1;
	long long n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)sa = 0;
	}
	sort(a+1,a+n+1);
	int sb = 1,pir = a[2]-a[1];
	for(int i = 3;i<=n;i++){
		if(a[i]-a[i-1]!=pir)sb = 0;
	}
	int goal = 2;
	if(sa||sb){
		for(;;){
			long long step = 0;
			for(;;goal++){
				long long ms = a[goal]-a[1],mw = a[goal]-a[goal-1];
				step = (ms+mw)*(goal-1)/2;
				if(step>m){
					goal-=1;
					break;
				}
			}
			cout<<goal;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	for(;;){
		long long step = 0;
		for(int i = 1;i<goal;i++){
			step += (a[goal]-a[i]);
		}

		if(step<=m&&step>=0){
			m-=step;
			for(int i = 1;i<goal;i++){
				a[i] = a[goal];
			}
			goal++;
		}else{
			break;
		}
	}
	cout<<goal-1;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
