#include<iostream>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long Answer=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int Left=1,Right=n;
	while(Left<=Right){
		int Mininum=min(a[Left],a[Right]);
		if(c[Left]!=c[Right]){
			Answer+=Mininum;
		}
		if(Mininum==a[Left]&&Mininum==a[Right])Left++,Right--;
		else if(Mininum==a[Left])Left++,a[Right]-=Mininum;
		else Right--,a[Left]-=Mininum;
	}
	cout<<Answer;
	return 0;
}
//背负最弱oier之名，我不能AC。 
