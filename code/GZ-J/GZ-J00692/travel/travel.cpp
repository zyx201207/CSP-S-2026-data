//GZ-J00692,尚泽瑞，思源实验学校
int main{
	string a;
	string b;
	string c;
	string d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	if(a == b){
		cout << 1;
	}
	if(a != b){
		cout << 0000;
		return 0;
	}
	if(b[1] == d[1]){
		if(b[2] == d[2]){
			cout << 1;
		}
		if(b[2] != d[2]){
			cout << 000;
			return 0;
		}
	}
	if(b[1] != d[1]){
		cout << 000;
		return 0;
	}
	if(b[3] == "A"){
		if(d[3] == "B"){
			cout << 11;
			return 0;
		}
		if(d[3] == "C"){
			cout << 10;
			return 0;
		}
		if(d[3] == "D"){
			cout << 00;
			return 0;
		}
		if(d[3] == "F"){
			cout << 00;
			return 0;
		}
	}
	if(b[3] == "B"){
		if(d[3] == "A"){
			cout << 11;
			return 0;
		}
		if(d[3] == "C"){
			cout << 11;
			return 0;
		}
		if(d[3] == "D"){
			cout << 00;
			return 0;
		}
		if(d[3] == "F"){
			cout << 00;
			return 0;
		}
	}
	if(b[3] == "C"){
		if(d[3] == "B"){
			cout << 11;
			return 0;
		}
		if(d[3] == "A"){
			cout << 10;
			return 0;
		}
		if(d[3] == "D"){
			cout << 00;
			return 0;
		}
		if(d[3] == "F"){
			cout << 00;
			return 0;
		}
	}
	if(b[3] == "D"){
		if(d[3] == "B"){
			cout << 00;
			return 0;
		}
		if(d[3] == "C"){
			cout << 00;
			return 0;
		}
		if(d[3] == "A"){
			cout << 00;
			return 0;
		}
		if(d[3] == "F"){
			cout << 11;
			return 0;
		}
	}
	if(b[3] == "F"){
		if(d[3] == "B"){
			cout << 00;
			return 0;
		}
		if(d[3] == "C"){
			cout << 00;
			return 0;
		}
		if(d[3] == "A"){
			cout << 00;
			return 0;
		}
		if(d[3] == "D"){
			cout << 11;
			return 0;
		}
	}
} 
