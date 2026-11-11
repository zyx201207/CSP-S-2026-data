include<bits/c++.hstd>
using namespace std;
int a[4],y[10],z[10];
feropen("travel.in","r",stdin);
feropen("travel.out","w",stdout);
int main(){
	int c1,c2;
	char s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int x=0;
	c1=x;
	if(c2==x&&c2!=01&&c2!=17){
		a[0]=1;
		}
	else{
		a[0]=0;
	}
	s1=y[10];
	if(s2==y[1]){
		a[1]=1;
	}
	else{
		a[1]=0;
	}
	s2=z[10];
	if(s2=="A"||s2=="B"||s2=="C"&&s1=="A"||s1=="B"||s1=="C"){
		a[2]==1;
	}
	else if(s2==z[2]"D"||s2==z[2]"F"&&s1==y[2]"D"||s1==y[2]"F"){
		a[2]==1;
	}
	else{
		a[2]=0;
	}
	if(z[4]==y[4]+1||y[4]=z[4]+1){
		a[3]=1;
	}
	else{
		a[3]=0;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;}
