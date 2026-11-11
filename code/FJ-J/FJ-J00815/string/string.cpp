#include <bits/stdc++.h> 
using namespace std;
int n,size,ans=0;
int number[200005];
char letter[200005];
int main(){
	ifstream fin("string.in");
	ofstream fout("string.out");
	fin>>n;
	int i=0;
	string o;
	while(n--){
		fin>>number[i]>>letter[i];
		for(int j=0;j<number[i];j++){
			o+=letter[i];
			size++;
		}
		i++;
	}
	for(int j=0;j<size;j++){
		if(o[j] != o[size-1]) ans++;
		size--;
	}
	fout<<ans;
	return 0;
}
