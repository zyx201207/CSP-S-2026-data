#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,x1,x2;
	cin >> c1 >> s1 >> c2 >> s2;
	long long a,b,c,d;
	stringstream ss;
	ss>>c1;
	ss<<a;
	ss>>c2;
	ss<<b;
	if(a==b){
		cout << 1;
	}else{
		cout << "0000"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<2;i++){
		x1[i]=s1[i];
	}
	for(int i=0;i<2;i++){
		x2[i]=s2[i];	
	}
	ss>>x1;
	ss<<c;
	ss>>x2;
	ss<<d;
	if(c==d){
		cout << 1;
	}else{
		cout << "000"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	char e=s1[2],f=s2[2];
	long long g=e,h=f,i='C',j='D';
	if((g<=i&&h<=j)||(g>=i&&h>=j)){
		cout << 1;
		if(g+1==h||g-1==h){
			cout << 1<<endl;
		}else{
			cout << 0<<endl;
		}
	}else{
		cout << 0 << 0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
