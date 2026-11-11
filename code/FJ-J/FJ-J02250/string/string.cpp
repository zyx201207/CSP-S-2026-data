#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
long long n,a[114514],Master_Spark;
string c[114514],s;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	//cout<<s<<endl;
	
	for(int i=0;i<s.length()/2;i++){
		if(s[i]-'0'!=s[s.length()-i-1]-'0')Master_Spark++;
		//cout<<s[i]<<' '<<s[s.length()-i-1]<<' '<<Master_Spark<<endl;
	}
	

	cout<<Master_Spark;
}
