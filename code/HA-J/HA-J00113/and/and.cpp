#include<iostream>
#include<algorithm>
using namespace std;
int a[200005],Top;
string Base2[200005];
string Excellent[2][200005];
string To_base2(int Number){
	if(Number==0)return "0";
	string Answer="";
	while(Number!=0){
		Answer+=Number%2+'0';
		Number/=2;
	}
	reverse(Answer.begin(),Answer.end());
	return Answer;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,Max_size=0;
	cin>>n>>m;
	Top=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Base2[i]=To_base2(a[i]);
		Max_size=max(Max_size,int(Base2[i].size()));
	}
	for(int i=1;i<=n;i++){
		while(Base2[i].size()!=Max_size){
			Base2[i]="0"+Base2[i];
		}
		Excellent[0][i]=Base2[i];
	}
	for(int i=0;i<Max_size;i++){
		int Count=0;
		for(int j=1;j<=Top;j++){
			if(Excellent[0][j][i]=='1'){
				Excellent[1][++Count]=Excellent[0][j];
			}
		}
		if(Count>=m){
			for(int j=1;j<=Count;j++){
				Excellent[0][j]=Excellent[1][j];
			}
			Top=Count;
		}
	}
	int Power2=0,Answer=-1;
	for(int i=1;i<=m;i++){
		int Number=0;
		for(int j=Max_size-1;j>=0;j--){
			Number=Number+((Excellent[0][i][j]-'0')<<Power2);
			Power2++;
		}
		Power2=0;
		if(Answer==-1){
			Answer=Number;
		}else{
			Answer&=Number;
		}
	}
	cout<<Answer;
	return 0;
}
//背负最弱oier之名，我不能AC。 
