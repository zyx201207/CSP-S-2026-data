#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	string arr="";
	cin >> a;
    long long b[a+1];
    char c[a];
    b[0]=0;
    for(int i=0;i<a;i++){
    	cin>>b[i+1]>>c[i];
    	b[i+1]+=b[i];
	}
	cout << endl;
	long long s=b[a];
	long long mid=(s%2==0?s/2-1:s/2);
	long long num=1;
	char c1,c2;
	long long to=0;
	if(s%2==0){
		while(mid>=num){
		    for(int i=0;i<a;i++){
		    	if(mid-num+1>=b[i]&&mid-num+1<=b[i+1]){
		    		c1=c[i];
		    		break;
				}
				if(mid+num>=b[i]&&mid+num<=b[i+1]){
		    		c2=c[i];
		    		break;
				}
			}
			if(c1!=c2){
				to++;
			}
		    num++;
	    }
	    to++;
	}else{
		while(mid>=num){
		    for(int i=0;i<a;i++){
		    	if(mid-num>=b[i]&&mid-num<=b[i+1]){
		    		c1=c[i];
		    		break;
				}
				if(mid+num>=b[i]&&mid+num<=b[i+1]){
		    		c2=c[i];
		    		break;
				}
			}
			if(c1!=c2){
				to++;
			}
		    num++;
	    }
	}
	
	cout <<to<<endl;
	
	return 0;
}