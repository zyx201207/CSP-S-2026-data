////GZ-J00599 贵阳市白云区第二高级中学 王良楷锋
#include<iostream>
#include<vector>
using namespace std;
int n,m;


int main(){
	cin >> n >> m;
	vector<int> card(n);	
	vector<int> num(m);
	for (int i=0;i<m;i++) num[i] = 0;
	
	for (int i=0;i<n;i++) cin >> card[i];
	
	for(int k=0;k<n;k++){
		vector<int> temp;
		for (int i=k;i<n;i++){
			temp.insert(temp.end(), num[i]);
			for (int j=k;j<i;j++){
				if (temp[j] == card[i]){
					temp[j] = 0;
				}
			}
			
		}
		
		for (int o=1;o<=m;o++){
			for (int i=0;i<temp.size();i++){
				if (temp[i] == o) num[o-1]++;
			}
		}
	}
	
	for (int i=0;i<m;i++) cout << num[i] << ' ';
	return 0;
}