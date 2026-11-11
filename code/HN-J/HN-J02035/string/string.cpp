#include <iostream> 
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	
	int n,t=0,st=0,i=1,tt=0;
	cin >> n;
	char a[200005],b[n+5],c;
	for(i=1;i<=n;i++){
		int m;
		cin >> m >> c;
		for(int j=1;j<=m;j++){
			tt=j;
			a[t+tt]=c;
		}
		t=t+tt;
	}
	i=1;
	if(t%2==0){
		while(i+1<t){
			if(a[i]!=a[t]){
				st++;
			}
			i++;
			t--;
		}
	}else{
		while(i<=t){
			if(a[i]!=a[t]){
				st++;
			}
			i++;
			t--;		
		}
	}
	cout << st;
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
